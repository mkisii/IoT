# -*- coding:utf-8 -*-
import json
import os

import yaml
from yaml.scanner import ScannerError

from .constants import FormatType
from .exceptions import ArgumentInvalid, InputFormatInvalid, ConversionError


class Formatter(object):
    """
    Read data from one format and then output as another.
    """

    def __init__(self, data_format, raw_data=None, file_path=None, human=False):  # data source: data >= file_path
        """
        :param data_format: the format of input data, should be one of:
            FormatType.JSON: indicates the raw_data is in json format
            FormatType.YAML: indicates the raw_data is in yaml format
            FormatType.PYTHON: indicates the raw_data is a python native object

        :param raw_data: data to format, this will be read first. If data_format is FormatType.PYTHON, this will only be read.

        :param file_path: file_path to read data from, this will be read second if no data is provided

        :param human: shows if the output should be showed in a human-readable format
        """
        if data_format not in FormatType.to_list():
            raise ArgumentInvalid('"data_format" should be one of FormatType.JSON / YAML / PYTHON!')
        self.data_format = data_format
        self.raw_data = raw_data
        self.file_path = file_path
        self.human = human

        self.data = None  # presents the python native object of raw_data

        self._load_data()
        self._validate()

    def _load_data(self):
        """
        Load data from raw_data or file_path
        """
        if self.raw_data is None and self.data_format is not FormatType.PYTHON:
            if self.file_path is None:
                raise ArgumentInvalid('One of "raw_data" or "file_path" should be set!')
            if not os.path.isfile(self.file_path) or not os.access(self.file_path, os.R_OK):
                raise ArgumentInvalid('"file_path" should be a valid path to an exist file with read permission!')
            with open(self.file_path) as f:
                self.raw_data = f.read()

    def _validate(self):
        """
        Validate the input data.
        """
        if self.data_format is FormatType.PYTHON:
            self.data = self.raw_data
        elif self.data_format is FormatType.JSON:
            self._validate_json()
        elif self.data_format is FormatType.YAML:
            self._validate_yaml()

    def _validate_json(self):
        try:
            self.data = json.loads(self.raw_data)
        except Exception:
            raise InputFormatInvalid('The input data cannot be decoded as JSON.')

    def _validate_yaml(self):
        try:
            self.data = yaml.load(self.raw_data)
        except ScannerError:
            raise InputFormatInvalid('The input data cannot be decoded as YAML.')

    def get_formatted_output(self, format_type=FormatType.JSON):
        """
        :param format_type: The format need to output.
        :return: formatted output.
        :raise ConversionError: data can't be converted to the specified format_type.
        """
        if format_type not in [FormatType.JSON, FormatType.YAML]:
            raise ArgumentInvalid('"format_type" should be one of FormatType.JSON / YAML!')
        elif format_type is FormatType.JSON:
            return self._format_json()
        elif format_type is FormatType.YAML:
            return self._format_yaml()

    def _format_json(self):
        try:
            if self.human:
                return json.dumps(self.data, indent=4)
            return json.dumps(self.data)
        except Exception:
            raise ConversionError('The data can\'t be converted to JSON!')

    def _format_yaml(self):
        try:
            if self.human:
                return yaml.safe_dump(self.data, default_flow_style=False)
            return yaml.safe_dump(self.data)
        except Exception:
            raise ConversionError('The data can\'t be converted to YAML!')

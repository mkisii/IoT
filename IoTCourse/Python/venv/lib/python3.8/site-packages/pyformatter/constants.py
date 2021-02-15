# -*- coding:utf-8 -*-


class FormatType(object):
    JSON = 'json'
    YAML = 'yaml'
    PYTHON = 'python'

    @staticmethod
    def to_list():
        return [FormatType.JSON, FormatType.YAML, FormatType.PYTHON]

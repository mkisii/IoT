# -*- coding:utf-8 -*-


class BaseFormatException(Exception):
    pass


class InputFormatInvalid(BaseFormatException):
    pass


class ArgumentInvalid(BaseFormatException):
    pass


class ConversionError(BaseFormatException):
    pass

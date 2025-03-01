import re

def contains_characters(string, pattern):
    """
    Checks if the given string contains all characters in the pattern.
    :param string: The input string to check.
    :param pattern: A string containing the required characters.
    :return: True if all characters in the pattern are found in the string, otherwise False.
    """
    regex_pattern = f"[{pattern}]"
    return bool(re.search(regex_pattern, string))

# Example usage:
string = "Hello, welcome to Python programming!"
pattern = "xyz"

if contains_characters(string, pattern):
    print("The string contains at least one of the specified characters.")
else:
    print("The string does not contain any of the specified characters.")

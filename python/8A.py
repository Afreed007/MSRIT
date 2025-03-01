import re

def contains_characters(string, pattern):
    regex_pattern = f"[{pattern}]"
    return bool(re.search(pattern, string))

# Example usage:
string = "Hello, welcome to Python programming 123!"
pattern = r"[a-z][A-Z][0-9]"

if contains_characters(string, pattern):
    print("The string contains at least one of the specified characters.")
else:
    print("The string does not contain any of the specified characters.")

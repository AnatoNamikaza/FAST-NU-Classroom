'''Write a Python program to create a new dictionary by extracting the mentioned keys from the below dictionary.
Sample Dictionary:
sample_dict = {
    "name": "Kelly",
    "age": 25,
    "salary": 8000,
    "city": "New york"}
# Keys to extract
keys = ["name", "salary"]'''

sample_dict = {
    "name": "Kelly",
    "age": 25,
    "salary": 8000,
    "city": "New york"}
# Keys to extract
keys = ["name", "salary"]
new_dict = {key:sample_dict[key] for key in keys}
print(new_dict)


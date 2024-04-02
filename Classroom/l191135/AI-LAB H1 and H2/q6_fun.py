''' write a python program to change Brad's salary to 8500 in the following dictionary'''
sample_dict = {
    'emp1': {'name': 'Jhon', 'salary': 7500},
    'emp2': {'name': 'Emma', 'salary': 8000},
    'emp3': {'name': 'Brad', 'salary': 500}
}

def update_sal(dic,name, sal):
    for key in dic.keys():
        new_dict = dic[key]
        if new_dict['name'] == name:
            new_dict['salary'] = sal
            
update_sal(sample_dict,'Brad',8500)
print(sample_dict)

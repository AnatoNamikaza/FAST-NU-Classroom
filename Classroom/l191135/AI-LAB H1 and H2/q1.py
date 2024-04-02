'''For a list of integers, find square and cube for each value using lambda function'''
number_list = [1,2,3,4]
fl = lambda num_list: [[index**2, index**3] for index in num_list]
print(fl(number_list))


'''Set in Python is a data structure equivalent to the sets in mathematics. It is a mutable collection of
distinct (unique) values that are unordered. Consider two sets A= {“tyres”, “gear”, “lights”,
“mirrors”} and B= {“rims”, “doors”, “steering”, “gear”, “tyres”}. Return a new set of identical
items from the given two sets. (10 mark)'''

def intersection(set1,set2):
    return(set1.intersection(set2))

print(intersection(set({1,2}),set({2,3})))

def losing_team_captain(teams):
    return(teams[-1][1])

print(losing_team_captain([["zaeem","askar","other"],["cr","shehmeer"]]))

def mul_by_num(num):
    x = num;
    return(lambda n: n*x)

x = mul_by_num(3)
print(x(2))


from unittest import removeHandler


# Name:       Abdul Rehman
# Rollno:     19L-1135
# Section:    CS-6A
# ++++++++++++++++++++++++++
import random as rd

# Print function
def view(li, index):
    print("\nSolution number#",index + 1,": ", li, "\n")
    i = 0
    while i < 8:
        pos = li[i] - 1
        j = 0
        while j < 8:
            if j == pos:
                print('[Q]', end='')
            else:
                print('[ ]', end='')
            j += 1    
        i += 1        
        print()

# Fitness function
def getFitness(instance):
    clashes = 0
    limit, i = (len(instance) - 1), 0
    while i < limit:
        for j in range(i + 1, len(instance)):
            if (instance[i] == instance[j]) or (abs(instance[j] - instance[i]) == abs(j - i)):
                clashes += 1
        i += 1        
    return 28 - clashes


# Child Creation function
def buildKid(instance1, instance2, crossOver):
    newInstance = []
    for i in range(crossOver):
        newInstance.append(instance1[rd.randint(0, 7)])
        newInstance.append(instance2[rd.randint(0, 7)])
    return newInstance

# Huristic function
def getHuristic(instance):
    huristic = []
    limit, i = len(instance), 0
    while i < limit:
        j = i - 1
        huristic.append(0)
        for j in range (j, -1, -1):
            if instance[i] == instance[j] or (abs(instance[i] - instance[j]) == abs(i - j)):
                huristic[i] += 1
        j = i + 1
        for j in range(len(instance)):
            if instance[i] == instance[j] or (abs(instance[i] - instance[j]) == abs(i - j)):
                huristic[i] += 1
        i += 1    
    return huristic

# Child function
def changeChilds(co):
    global father, mother, child1, child2, crossover
    crossover = co
    child1 = buildKid(father, mother, crossover)
    child2 = buildKid(mother, father, crossover)

# Chromosome function
def changeChromosome(li):
    global crossover, father, mother
    newchange = -1
    while newchange != 0:
        newchange = 0
        tmpli = li
        getHur = getHuristic(tmpli)
        index = getHur.index(max(getHur))
        maxFitness = getFitness(tmpli)
        i = 1
        while i < 9:
            tmpli[index] = i
            if getFitness(tmpli) > maxFitness:
                maxFitness = getFitness(tmpli)
                newchange = i
            tmpli = li
            i += 1

        if newchange == 0:
            i = 0
            while i < (len(li) - 1):
                j = i + 1
                while j < (len(li)):
                    if li[i] == li[j]:
                        li[j] = rd.randint(1, 8)
                    j += 1    
                i += 1        
        else:
            li[index] = newchange


#--------------- Main Body ---------------
print("Enter No. of Solutions you wish to find: ", end='')
no_of_sols = int(input())

sols = []
crossover = 4
while len(sols) < no_of_sols:
    father = []
    mother = []
    i = 0
    while i < 8:
        father.append(rd.randint(1, 8))
        mother.append(rd.randint(1, 8))
        i += 1
    fitnessFather = getFitness(father)
    fitnessMother = getFitness(mother)
    while fitnessFather != 28 and fitnessMother != 28:
        changeChilds(crossover)
        changeChromosome(child1)
        fitnessFather = getFitness(child1)
        father = child1
        changeChromosome(child2)
        fitnessMother = getFitness(child2)
        mother = child2
    if getFitness(father) == 28:
        if father not in sols:
            sols.append(father)
    else:
        if mother not in sols:
            sols.append(mother)

print("\n\n________________ Solutions ________________\nThe number of sols you wanted:", no_of_sols)
limit, i = len(sols), 0
while i < limit:
    view(sols[i], i)
    i += 1
    
print("___________________________________________")

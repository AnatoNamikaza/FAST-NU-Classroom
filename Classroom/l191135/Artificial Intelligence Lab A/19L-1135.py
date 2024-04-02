#Question-1
#Part-1:
# def get_substring_position(str1, str2):

#     count = 0
#     for i in range(len(str1)):
#         if i < (len(str1)) - 2:
#                 for j in range(len(str2)):            
#                     if str1[i]==str2[j]:
#                         if str1[i+1]==str2[j+1]:
#                             count+=1

#     return count                

# str1 = "docatzz"
# str2 = "dobatz"

# print(get_substring_position(str1,str2))

#Part-2:
# def tuple_div_6(test_list):
#     result = []
#     for t in test_list:
#         is_divisable = 1
#         for i in t:
#             if i % 6 != 0:
#                 is_divisable = 0

#         if is_divisable == 1:
#             result.append(t)

#     return result

# test_list = [(6, 24, 12), (60, 12, 6), (12, 18, 21)]
# print(tuple_div_6(test_list))

#Part-3:
# def common(a, b):
#     if len(set(a) & set(b)) != 0:
#         print("True")  
#     else:
#         print("False")  
# a = [1, 2, 3, 4, 5] 
# b = [5, 6, 7, 8, 9]
# common(a, b)

# #Part-4:
from ast import Global
import pandas as pd
import matplotlib.pyplot as plt
df = pd.read_csv("googleplaystore.csv",header=None)
df.columns=['App', 'Category', 'Rating', 'Reviews', 'Size', 'Installs', 'Type', 'Price','Content Rating','Genres','Last Updated','Current Ver','Android Ver']
#Part_A
Category = df["Category"].unique
Count = df["Category"].value_counts
fig = plt.figure()
ax = fig.add_axes([0,0,1,1])
ax.bar(Category,Count)
plt.show()
#Part_B
most_installed = df.sort_values(by="Installs",ascending=False).first(10)

#Part_C
most_installed = df.sort_values(by="Installs",ascending=False).first(10)
#Part-5:
# import numpy as np
# #lets A and B is 
# A = np.ones(3)*1
# B = np.ones(3)*2
# print(((A+B)*(-A/2)))

#Part-6:
# from random import shuffle

# class Card:
#     def __init__(self, suit, value):
#         self.suit = suit
#         self.value = value

#     def __repr__(self):
#         return "{} of {}".format(self.value, self.suit)

# class Deck(Card):
#     def __init__(self):
#         self.cards = []
#         suits = ['Hearts','Diamonds','Clubs','Spades'] 
#         values = ['A','2','3','4','5','6','7','8','9','10','J','Q','K']
#         ## write your code here ##

#         for i in suits:
#             for j in values:
#                 self.cards.append(Card(i,j))

#     def __repr__(self):
#         return "Cards remaining in deck: {}".format(len(self.cards))

#     def shuffle(self):
#         if len(self.cards) < 52:
#             raise ValueError("Only full decks can be shuffled")
#         shuffle(self.cards)
#         return self

#     def deal(self):
#         if len(self.cards) == 0:
#             raise ValueError("All cards have been dealt")
#         return self.cards.pop()

# deck1 = Deck()
# deck1.shuffle()
# while deck1.__repr__() != 0:
#     print(deck1.deal())



#Question-2
#Valid Genes
import random
 
# Number of individuals in each generation
POPULATION_SIZE = 100
 
# Valid genes
GENES = '''abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOP
QRSTUVWXYZ 1234567890, .-;:_!"#%&/()=?@${[]}'''

TARGET = "Artificial Intelligence CL461; Fast-NU Lahore"

class Individual(object):
    '''
    Class representing individual in population
    '''
    def __init__(self, chromosome):
        self.chromosome = chromosome
        self.fitness = self.cal_fitness()
 
    @classmethod
    def mutated_genes(self):
        '''
        create random genes for mutation
        '''
        global GENES
        gene = random.choice(GENES)
        return gene
 
    @classmethod
    def create_gnome(self):
        '''
        create chromosome or string of genes
        '''
        global TARGET
        gnome_len = len(TARGET)
        return [self.mutated_genes() for _ in range(gnome_len)]
 
    def mate(self, par2):
        '''
        Perform mating and produce new offspring
        '''
        return self.chromosome+par2
        #write your code here (marks = 4)
 
    def cal_fitness(self):
        '''
        Calculate fitness score, it is the number of
        characters in string which differ from target
        string.
        '''
        #write your code here (marks =2 )
        global TARGET
        count = 0
        for i in range(len(TARGET)):
            if TARGET[i] != self.chromosome[i]: count = count + 1
        
        return (count/len(TARGET)*100) 


# Driver code
def main():
    global POPULATION_SIZE
 
    #current generation
    generation = 1
 
    found = False
    population = []
 
    # create initial population
    # write your code here (marks = 1)
    chromo = "urtificial Infelligence C3461; Fasg-NU Laho4e"
    vgs = Individual(chromo)

    for i in range(POPULATION_SIZE):
        dict = {"String":vgs.create_gnome(), "Fitness":vgs.cal_fitness()}
        population.append(dict)

    while not found:
 
        # sort the population in increasing order of fitness score
        population = sorted(population, key = lambda x:x.fitness)
 
        # if the individual having lowest fitness score ie.
        # 0 then we know that we have reached to the target
        # and break the loop
        if population[0].fitness <= 0:
            found = True
            break
 
        # Otherwise generate new offsprings for new generation
        new_generation = []
 
        # Perform Elitism, that mean 10% of fittest population
        # goes to the next generation
        s = int((10*POPULATION_SIZE)/100)
        new_generation.extend(population[:s])
 
        # From 50% of fittest population, Individuals
        # will mate to produce offspring
        s = int((90*POPULATION_SIZE)/100)
        for _ in range(s):
            parent1 = random.choice(population[:50])
            parent2 = random.choice(population[:50])
            child = parent1.mate(parent2)
            new_generation.append(child)
 
        population = new_generation
 
        print("Generation: {}\tString: {}\tFitness: {}".\
              format(generation,
              "".join(population[0].chromosome),
              population[0].fitness))
 
        generation += 1
 
     
    print("Generation: {}\tString: {}\tFitness: {}".\
          format(generation,
          "".join(population[0].chromosome),
          population[0].fitness))
 
if __name__ == '__main__':
    main()


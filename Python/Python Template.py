# Week 1 day two in-class activity #1
# File: ACT.1.Week 1.2
# Date:    15/1/2020
# By:      Jack Anthony Armstrong
#          Armstja
# Section: 003
# Team:    
# 
# ELECTRONIC SIGNATURE
# Jack Anthony Armstrong
#
# The electronic signature above indicates the script
# submitted for evaluation is my individual work, and I
# have a general understanding of all aspects of its
# development and execution.
#
# A BRIEF DESCRIPTION OF WHAT THE SCRIPT OR FUNCTION DOES

n = int(input('Input positive value for n '))
while n < 0:
    print('Invalid value for n')
    n = int(input('Input positive value for n '))


P = [3,0,2]


for x in range(3, (n + 1)):
    PN = P[x - 2] + P[x - 3]
    P.append(PN)


n = 0

print(P)


      

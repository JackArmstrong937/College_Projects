# HW_2p1__Task1_TEAM040_armstja
# File: HW_2p1__Task1_TEAM040_armstja.py
# Date:    30/1/2020
# By:      Jack Anthony Armstrong
#          Armstja
# Section: 003
# Team: 0404    
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
# This script prompts the user for a positive interger for 'n'. It then checks to see if
# the inputed value is valid (greater than 0), then it computes the Perrin number sequence
# for terms 3 - 5, with the 0 - 2 terms aready given. The script then outputs the perrin number
# list with terms 0 - 5.

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


      

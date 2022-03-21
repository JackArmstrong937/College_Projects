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

import math

P = float(input("Value for Pressure "))
Un = str(input("Units for Pressure (Pascals or psi) "))
UnD = str(input("Desired Units for Pressure (Pascals or psi)"))

if Un != "Pascals" and Un != "psi":
    print("Error, unit type is invalid")
else:
    if Un == "Pascals" and UnD == "psi":
         NewP = P * 0.000145038
         print("New Pressure value = {0:2f}".format (NewP))

    else:
        NewP = P * 6894.76
        print("New Pressure value = {0:2f}".format (NewP))
            


    

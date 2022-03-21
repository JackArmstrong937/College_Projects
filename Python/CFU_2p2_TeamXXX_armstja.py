# Week 1 day two in-class activity #1
# File: CFU_2p2_TeamXXX_armstja
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


fid = open('Grades','r')
Grades = fid.realines()
fid.close()

if Grades[0:()] >= 90:
     A = len(Grades)
     print("Number of A grades". fromat(A))
     
elif Grades[0:()]>=80 and Grades[0:()] <90:
     B = len(Grades)
     print("Number of B grades". fromat(B))

elif Grades[0:()] >=70 and Grades[0:()] < 80:
     C = len(Grades)
     print("Number of C grades". fromat(C))

elif Grades[0:()] >=60 and Grades[0:()] < 70:
     D = len(Grades)
     print("Number of D grades". fromat(D))

else Grades[0:()] <60:
     F = len(Grades)
     print("Number of F grades". fromat(F))

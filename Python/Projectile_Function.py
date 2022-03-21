# Projectile Function
# File: Projectile_Function
# Date:    30/1/2020
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


#Calling Projectile Values file

fid = open('Projectile_Values','r')

IntVel[0:15] = fid.readlines()

LaunchAngl[0:15] = fid.readlines()

fid.close

import math

def Projectile(ListI, ListM, ListD):




#T of impact

    for x in range(0,15,1):
        Timpact = (2 * (IntVel[x]) * ( math.sin(LaunchAngl[x] * (pi / 180)))) / (9.81)

        ListI.append(Timpact)

        return(ListI)
    
    
#T of max height
    
    for x in range(0,15,1):
        Tmax = (IntVel[x]) * (math.sin(LaunchAngl[x] * (pi / 180))) / (9.81)

        ListM.append(Tmax)

        return(ListM)
    
    
#Horizontal Distance

    for x in range(0,15,1):
        HorzDis = (IntVel[x]) * (math.cos(LaunchAngl[x] * (pi / 180))) * (Timpact + Tmax)
    
        ListD.append(HorzDis)

        return(ListD)

    




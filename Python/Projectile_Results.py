# Projectile_Results
# File: Projectile_Results.txt
# Date:  30/1/2020
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

import Projectile.Projectile_Values(ListI, ListM, ListD)

fid = open('Projectile_Values','r')

IntVel[0:15] = fid.readlines()

LaunchAngl[0:15] = fid.readlines()

fid.close

print(IntVel[0:15][0],
      LaunchAngl[0:15][1],
      ListI[0:15][2],
      ListM[0:15][3],
      ListD[0:15][4])

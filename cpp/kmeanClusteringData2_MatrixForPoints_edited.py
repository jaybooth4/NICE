import numpy as np
import matplotlib.pylab as plt
import math 
import time 

#--Ahmed Chegeunni--(7/14/2016)---#

K = 3  # we will have K clusters

#m_u=np.random.rand(K,2)   
m_u=np.array([[400,100],[400,123],[340,300]])
'''
RandX=np.array([[1,5,1.5,8,1,9,4,3,4]])
RandY=np.array([[2,8,1.8,8,0.6,11,3,4,0]])

'''
RandX=np.array([[338.652, 338.937, 331.573, 362.854, 336.885, 319.333, 318.096, 336.301, 355.569, 307.939, 343.901, 336.176, 338.521, 340.818, 341.627, 350.683, 340.15, 318.637, 319.573, 342.832, 309.813, 334.145, 336.954, 361.812, 309.679, 329.919, 334.344, 347.357, 328.954, 351.093, 337.523, 359.593, 331.626, 347.557, 376.009, 328.079, 342.376, 327.012, 330.624, 336.88, 341.964, 342.776, 345.873, 320.215, 330.036, 345.472, 338.167, 340.711, 353.404, 331.691, 350.628, 355.918, 350.626, 325.008, 336.177, 340.941, 362.816, 343.212, 326.957, 324.528, 344.76, 332.502, 348.975, 341.357, 320.1, 338.135, 331.813, 325.052, 359.555, 333.39, 310.404, 342.608, 329.62, 340.228, 313.894, 341.441, 344.897, 327.367, 347.171, 361.866, 316.796, 328.909, 338.614, 367.859, 330.065, 357.752, 319.503, 344.109, 321.979, 361.923, 337.489, 318.097, 336.894, 356.989, 346.41, 343.377, 367.785, 313.689, 332.276, 320.29, 366.058, 355.786, 374.531, 364.933, 354.194, 388.843, 361.705, 356.804, 358.444, 369.455, 384.437, 362.962, 369.264, 359.394, 371.515, 346.499, 373.083, 387.33, 345.231, 363.31, 361.773, 350.627, 369.221, 344.565, 345.387, 372.61, 383.768, 370.829, 361.262, 394.445, 363.812, 373.473, 350.764, 385.392, 349.843, 355.751, 376.896, 358.753, 380.512, 374.029, 364.957, 344.819, 322.27, 363.833, 339.556, 361.016, 348.324, 411.534, 380.654, 361.209, 377.675, 379.051, 371.384, 369.004, 389.083, 349.681, 374.336, 381.387, 371.142, 340.114, 394.004, 377.061, 366.092, 381.004, 348.348, 379.066, 390.212, 357.244, 366.239, 362.882, 337.091, 351.198, 365.125, 370.721, 367.719, 380.278, 363.755, 362.922, 366.828, 367.469, 371.73, 382.612, 393.388, 354.896, 372.29, 362.302, 386.175, 380.768, 375.597, 395.223, 363.813, 396.789, 360.169, 374.58, 358.454, 356.245, 343.756, 365.045, 370.184, 371.821, 284.835, 249.505, 276.101, 296.966, 302.579, 300.601, 297.634, 278.923, 286.451, 290.056, 331.682, 271.496, 290.73, 258.429, 293.937, 277.883, 259.927, 275.594, 273.719, 305.546, 273.839, 315.81, 269.932, 266.953, 284.474, 292.193, 295.399, 301.11, 265.195, 287.143, 292.935, 239.226, 292.024, 293.863, 284.487, 302.39, 285.783, 303.401, 313.514, 305.782, 282.534, 261.164, 274.948, 280.873, 296.84, 271.946, 304.39, 286.825, 256.569, 302.872, 258.001, 259.18, 292.09, 284.466, 272.995, 291.989, 277.61, 264.54, 282.032, 285.196, 300.269, 283.027, 283.285, 301.081, 262.053, 280.884, 282.394, 261.695, 285.09, 281.387, 261.195, 288.001, 290.232, 282.477, 310.071, 295.887, 303.874, 283.244, 273.221, 280.611, 284.668, 295.649, 278.385, 275.114, 293.729, 252.987, 276.928, 301.54, 292.62, 265.639, 306.981, 312.732, 300.424, 294.827, 307.118, 298.471, 273.463, 310.274, 301.643, 283.868]])
RandY=np.array([[174.119, 187.402, 150.22, 174.968, 188.909, 173.957, 165.885, 178.727, 165.375, 186.853, 178.542, 156.172, 207.568, 160.552, 197.475, 167.016, 160.835, 160.768, 165.29, 183.595, 171.184, 169.404, 170.996, 189.892, 148.733, 152.699, 188.785, 188.986, 169.886, 179.699, 179.475, 167.057, 190.184, 151.755, 177.127, 155.821, 142.984, 164.468, 183.48, 202.228, 175.336, 158.083, 184.969, 156.543, 195.746, 176.146, 176.677, 167.44, 167.634, 167.365, 163.297, 187.127, 160.536, 171.627, 189.602, 161.036, 166.882, 184.375, 166.292, 138.718, 170.41, 165.259, 194.378, 164.229, 158.34, 166.713, 159.831, 172.679, 166.127, 176.624, 199.089, 135.661, 170.298, 177.124, 180.281, 174.378, 180.025, 186.737, 152.272, 179.397, 185.887, 172.645, 173.386, 160.11, 176.356, 148.559, 162.25, 171.781, 168.474, 165.766, 175.874, 186.12, 181.842, 189.019, 166.986, 161.574, 187.899, 190.366, 166.24, 165.088, 75.1051, 64.5348, 83.4562, 72.0693, 82.2025, 89.8356, 70.0076, 59.9793, 50.1605, 102.716, 87.1793, 56.0811, 62.6476, 66.9918, 56.7184, 90.0079, 84.8795, 88.4346, 84.4806, 87.233, 58.34, 102.448, 86.3572, 51.0797, 58.7938, 57.3758, 87.3236, 70.4393, 66.8463, 69.1513, 80.2163, 54.535, 103.791, 84.1138, 82.2002, 74.7693, 76.6214, 63.4809, 77.8796, 87.754, 90.6475, 73.2885, 86.2733, 75.1059, 64.9516, 73.9979, 63.1062, 64.591, 72.0261, 75.4528, 61.3944, 78.7709, 65.479, 67.9332, 76.2938, 90.123, 89.0643, 79.071, 59.2536, 70.2509, 73.664, 49.7674, 70.3301, 72.0637, 72.0321, 55.9484, 70.6104, 52.2281, 75.9994, 62.3463, 72.3811, 55.6091, 90.9036, 89.9283, 85.1671, 71.7372, 66.604, 92.3255, 57.249, 70.1217, 55.5586, 75.8633, 102.924, 64.2126, 89.207, 79.6736, 69.9615, 70.5711, 77.1141, 76.8362, 62.534, 84.1376, 95.8467, 51.8068, 76.5465, 46.9484, 75.2167, 51.1948, 48.0781, 96.8465, 298.061, 278.831, 288.414, 287.78, 294.265, 291.793, 319.714, 287.637, 286.11, 307.518, 303.785, 289.61, 310.026, 287.946, 289.138, 280.58, 323.32, 305.688, 303.711, 292.166, 291.776, 303.077, 299.01, 302.325, 308.838, 296.892, 303.37, 296.347, 285.966, 301.021, 293.532, 306.7, 284.516, 280.144, 315.294, 322.962, 312.247, 312.669, 288.833, 305.815, 301.896, 298.541, 307.124, 306.824, 266.181, 309.434, 303.664, 288.277, 287.623, 300.749, 317.675, 296.175, 303.721, 312.728, 292.669, 301.805, 285.092, 288.709, 278.902, 300.914, 304.965, 276.353, 284.38, 287.068, 289.981, 312.532, 321.048, 300.748, 297.441, 297.056, 323.254, 320.505, 287.818, 296.621, 278.063, 294.568, 294.144, 302.279, 305.855, 313.237, 290.906, 310.151, 288.245, 279.567, 291.587, 289.49, 280.74, 311.229, 287.296, 313.356, 316.334, 291.44, 300.638, 285.862, 282.201, 304.895, 310.406, 280.222, 277.82, 309.236]])



#######
'''
n=5 # number of samples n 
data=np.random.rand(n,2) # generating random data points to plot 
'''
########

Dis_Matrix=np.empty ([np.size(RandX),K]) # Creating a matrix with dim of (len of pnts X K #)
 
m_u_old = np.zeros((K,2))

delta_mu=.00001


#while   np.mean(np.sum(np.square(m_u-m_u_old),axis=1)) > delta_mu: 

for o in range(0,6):
     
    m_u_old=m_u.copy() # set old mu to eaqual to new mu       
   
    Y=np.zeros([np.size(RandX),K]) # initialize matrix of all distances between mu & pts
    ID=[] # empty array for mu ID
    
    for j in range (0,K):
        mu_Dist=np.array( np.sqrt(np.square(abs(RandX-m_u[j,0])) + np.square(abs(RandY-m_u[j,1]))) ) # computing distances between each mu and points 
    
        Y[:,j]=mu_Dist[0,:]  #matrix of all distances between mu & pts
            
    for A in range(0,np.size(RandX)):    
        ID.append(np.argmin(Y[A,:]))  # creating an ID to each mu 
        
        ZpdMatrix=np.asarray(zip(np.transpose(RandX),np.transpose(RandY),ID)) #Matrix combining (X,Y,ID) of all points
        
    
    for L in range(0,K): 
        SrtdMatrix=ZpdMatrix[ZpdMatrix[:,2]==L,:] # sorted matrix returns [x,y,ID] of similar cluster points
        m_u[L,:]=(np.mean(SrtdMatrix[:,0]),np.mean(SrtdMatrix[:,1])) # mean of all (X & Y) values for Mu
    
###---delete later----###    
'''
print ZpdMatrix
print SrtdMatrix
print m_u 
print m_u_old
'''
#########################

plt.figure(1)
plt.scatter(RandX,RandY,c=ID,edgecolor='k',s=100)
plt.hold(True)
plt.scatter(m_u[:,0],m_u[:,1],marker='*',color='r',edgecolor='b' , s=400, label='centroids')
plt.grid(True)
plt.title('Kmean data clustering',fontsize=20)

plt.xlabel('X-axis',fontsize=18)
plt.ylabel('Y-axis',fontsize=18)
plt.legend()

plt.hold(False)

#plt.scatter(data[:,0],data[:,1])

plt.show()


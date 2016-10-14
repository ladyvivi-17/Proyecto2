
# coding: utf-8

# In[40]:

get_ipython().magic(u'matplotlib inline')
import numpy as np
import skfuzzy as fuzz
import matplotlib.pyplot as plt

x = np.arange(0, 30, 0.1)
mfx = fuzz.trimf(x, [1, 15, 30])
x2 = np.arange(25, 60, 0.1)
mfx2 = fuzz.trimf(x2, [25, 43, 60])
x3 = np.arange(50, 90, 0.1)
mfx3 = fuzz.trimf(x3, [50, 70, 90])
x4 = np.arange(80, 110, 0.1)
mfx4 = fuzz.trimf(x4, [80, 95, 110])
x5 = np.arange(100, 130,0.1)
mfx5 = fuzz.trimf(x5, [100, 115, 130])
x6 = np.arange(120, 150, 0.1)
mfx6 = fuzz.trimf(x6, [120, 135, 150])

plt.figure(figsize=(20, 5))

plt.plot(x, mfx, 'm', label = "Muy Baja ")
plt.plot(x2, mfx2, 'c', label = "Baja")
plt.plot(x3, mfx3, 'g', label = "Media")
plt.plot(x4, mfx4, 'r', label = "Normal ")
plt.plot(x5, mfx5, 'y', label = "Alta")
plt.plot(x6, mfx6, 'b', label = "Muy Alta ")

plt.title('Funcion de Membresia')
plt.ylabel("Grado de pertencia")
plt.xlabel("Temperatura")
plt.legend(loc=2)

plt.ylim(0, 1)
plt.xlim(0, 150)


plt.show()


# In[53]:

get_ipython().magic(u'matplotlib inline')
import numpy as np
import skfuzzy as fuzz
import matplotlib.pyplot as plt

x = np.arange(-12, -4, 0.1)
mfx = fuzz.trimf(x, [-12, -8.5, -5])
x2 = np.arange(-7, -2, 0.1)
mfx2 = fuzz.trimf(x2, [-7, -5, -3])
x3 = np.arange(-5, 4, 0.1)
mfx3 = fuzz.trimf(x3, [-5, -1, 3])
x4 = np.arange(0, 8, 0.1)
mfx4 = fuzz.trimf(x4, [0, 3.5, 7])
x5 = np.arange(5, 13,0.1)
mfx5 = fuzz.trimf(x5, [5, 8.5, 12])


plt.figure(figsize=(20, 5))

plt.plot(x, mfx, 'm', label = "Bajar Mucho ")
plt.plot(x2, mfx2, 'c', label = "Bajar Poco ")
plt.plot(x3, mfx3, 'g', label = "Mantener")
plt.plot(x4, mfx4, 'r', label = "Aumentar Poco ")
plt.plot(x5, mfx5, 'y', label = "Aumentar Mucho ")


plt.title('Variacion de Velocidad')
plt.ylabel("Grado de pertencia")
plt.xlabel(" Ajuste")
plt.legend(loc=2)

plt.ylim(0, 1)
plt.xlim(-12, 12)


plt.show()


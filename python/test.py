import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

x = np.linspace(0, (np.pi), 30)
y = np.sin(x)

plt.plot(x,y)
plt.show()
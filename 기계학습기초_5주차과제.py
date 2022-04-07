import matplotlib.pyplot as plt
import numpy as np
import mglearn
from sklearn.neighbors import KNeighborsRegressor
from sklearn.model_selection import train_test_split

lpn=1000
X, y = mglearn.datasets.make_wave(n_samples=50)
kns = np.zeros(lpn)
kss = np.zeros(lpn)
for i in range(lpn):
  train_input, test_input, train_target, test_target = train_test_split(X, y, train_size=0.7)
  knr = KNeighborsRegressor()
  knr.n_neighbors = 9
  knr.fit(train_input, train_target)
  kns[i] = knr.score(train_input, train_target)
  kss[i] = knr.score(test_input, test_target)

xs = np.linspace(-3,3,1000)
plt.plot(xs, knr.predict(xs.reshape(-1,1)))
plt.plot(train_input,train_target, '^')
plt.plot(test_input, test_target, 'v')
plt.title("K={}. train score:{:.2f}, test score:{:.2f}".format(knr.n_neighbors, np.mean(kns), np.mean(kss)))

plt.show()
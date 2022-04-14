!pip install mglearn
import sklearn
import matplotlib.pyplot as plt
import numpy as np
import mglearn
from sklearn.neighbors import KNeighborsRegressor
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression

perch_length = np.array([8.4, 13.7, 15.0, 16.2, 17.4, 18.0, 18.7, 19.0, 19.6, 20.0, 21.0,
       21.0, 21.0, 21.3, 22.0, 22.0, 22.0, 22.0, 22.0, 22.5, 22.5, 22.7,
       23.0, 23.5, 24.0, 24.0, 24.6, 25.0, 25.6, 26.5, 27.3, 27.5, 27.5,
       27.5, 28.0, 28.7, 30.0, 32.8, 34.5, 35.0, 36.5, 36.0, 37.0, 37.0,
       39.0, 39.0, 39.0, 40.0, 40.0, 40.0, 40.0, 42.0, 43.0, 43.0, 43.5,
       44.0])
perch_weight = np.array([5.9, 32.0, 40.0, 51.5, 70.0, 100.0, 78.0, 80.0, 85.0, 85.0, 110.0,
       115.0, 125.0, 130.0, 120.0, 120.0, 130.0, 135.0, 110.0, 130.0,
       150.0, 145.0, 150.0, 170.0, 225.0, 145.0, 188.0, 180.0, 197.0,
       218.0, 300.0, 260.0, 265.0, 250.0, 250.0, 300.0, 320.0, 514.0,
       556.0, 840.0, 685.0, 700.0, 700.0, 690.0, 900.0, 650.0, 820.0,
       850.0, 900.0, 1015.0, 820.0, 1100.0, 1000.0, 1100.0, 1000.0,
       1000.0])

lpn=1000

wdx, wdy = mglearn.datasets.make_wave(n_samples=100)


X = list(perch_length)+list(np.squeeze(wdx))
y = list(perch_weight)+list(wdy)

ad = np.column_stack([X, y])
at = np.concatenate((np.ones(56), np.zeros(100)))

kns = np.zeros(lpn)
kss = np.zeros(lpn)
lns = np.zeros(lpn)
lss = np.zeros(lpn)
rns = np.zeros(lpn)
rss = np.zeros(lpn)
for i in range(lpn):
  train_input, test_input, train_target, test_target = train_test_split(ad, at, stratify=at, train_size=0.7)
  train_poly = np.column_stack((train_input ** 2, train_input))
  test_poly = np.column_stack((test_input ** 2, test_input))
  knr = KNeighborsRegressor()
  lr = LinearRegression()
  l2r = LinearRegression()

  knr.n_neighbors = 3

  knr.fit(train_input, train_target)
  lr.fit(train_input, train_target)
  l2r.fit(train_poly, train_target)

  
  kns[i] = knr.score(train_input, train_target)
  kss[i] = knr.score(test_input, test_target)
  lns[i] = lr.score(train_input, train_target)
  lss[i] = lr.score(test_input, test_target)
  rns[i] = l2r.score(train_poly, train_target)
  rss[i] = l2r.score(test_poly, test_target)
  
plt.scatter(train_input[:, 0], train_input[:, 1])
plt.scatter(test_input[:, 0], test_input[:, 1])
plt.xlabel('X')
plt.ylabel('y')
plt.show()

print("최근접이웃 : train score:{:f}, test score:{:f}".format(np.mean(kns), np.mean(kss)))
print("선형회귀 : train score:{:f}, test score:{:f}".format(np.mean(lns), np.mean(lss)))
print("다항회귀 : train score:{:f}, test score:{:f}".format(np.mean(rns), np.mean(rss)))
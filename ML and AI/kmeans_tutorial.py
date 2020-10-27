#!/usr/bin/env python
# coding: utf-8

# <h1 align='center' style='color:purple'>Clustering With K Means - Python Tutorial</h1>

# In[9]:


from sklearn.cluster import KMeans
import pandas as pd
from sklearn.preprocessing import MinMaxScaler
from matplotlib import pyplot as plt
get_ipython().run_line_magic('matplotlib', 'inline')


# In[10]:


df = pd.read_csv("income.csv")
df.head()


# In[11]:


plt.scatter(df.Age,df['Income($)'])
plt.xlabel('Age')
plt.ylabel('Income($)')


# In[12]:


km = KMeans(n_clusters=3)
#basically value of K
y_predicted = km.fit_predict(df[['Age','Income($)']])
y_predicted


# In[13]:


df['cluster']=y_predicted
df.head()


# In[14]:


km.cluster_centers_


# In[15]:


df1 = df[df.cluster==0]
df2 = df[df.cluster==1]
df3 = df[df.cluster==2]
plt.scatter(df1.Age,df1['Income($)'],color='green')
plt.scatter(df2.Age,df2['Income($)'],color='red')
plt.scatter(df3.Age,df3['Income($)'],color='black')
plt.scatter(km.cluster_centers_[:,0],km.cluster_centers_[:,1],color='purple',marker='*',label='centroid')
plt.xlabel('Age')
plt.ylabel('Income ($)')
plt.legend()
#We get this type of graph because we haven't scaled our model yet!


# <h4 style='color:purple'>Preprocessing using min max scaler</h4>

# In[17]:


scaler = MinMaxScaler()

scaler.fit(df[['Income($)']])
df['Income($)'] = scaler.transform(df[['Income($)']])

scaler.fit(df[['Age']])
df['Age'] = scaler.transform(df[['Age']])
#scale between 0-1


# In[18]:


df.head()


# In[19]:


plt.scatter(df.Age,df['Income($)'])


# In[20]:


km = KMeans(n_clusters=3)
y_predicted = km.fit_predict(df[['Age','Income($)']])
y_predicted


# In[21]:


df['cluster']=y_predicted
df.head()


# In[23]:


km.cluster_centers_


# In[22]:


df1 = df[df.cluster==0]
df2 = df[df.cluster==1]
df3 = df[df.cluster==2]
plt.scatter(df1.Age,df1['Income($)'],color='green')
plt.scatter(df2.Age,df2['Income($)'],color='red')
plt.scatter(df3.Age,df3['Income($)'],color='black')
plt.scatter(km.cluster_centers_[:,0],km.cluster_centers_[:,1],color='purple',marker='*',label='centroid')
#We are iterating through cluster_centers_ 
plt.legend()
#Now these are correctly classified


# <h4 style='color:purple'>Elbow Plot</h4>

# In[24]:


sse = []
k_rng = range(1,10)
for k in k_rng:
    km = KMeans(n_clusters=k)
    km.fit(df[['Age','Income($)']])
    sse.append(km.inertia_)
#inertia gives sum of squared errors


# In[25]:


plt.xlabel('K')
plt.ylabel('Sum of squared error')
plt.plot(k_rng,sse)
#here we get our elbow at k=3 as we have also seen.


# <h4 style='color:purple'>Exercise</h4>

# <img src='iris.png' width=200 height=200>

# 1. Use iris flower dataset from sklearn library and try to form clusters of flowers using petal width and length features. Drop other two features for simplicity.
# 2. Figure out if any preprocessing such as scaling would help here
# 3. Draw elbow plot and from that figure out optimal value of k

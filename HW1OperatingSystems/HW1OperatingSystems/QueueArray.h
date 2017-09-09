#pragma once

#include <cstdlib>  //This is for the exit command.
#include <queue>

template <class QueueType>
class QueueArray
{
public:
  QueueArray(int numOfQueue);
  ~QueueArray();
  int Enqueue(const QueueType &item,const int index);
  QueueType Dequeue();
  int Qsize(int index);
  int Asize();
  int QAsize();
  QueueType* Qstate(int index);


private:
  int numOfQueues;
  std::queue<QueueType>* arrayOfQueues; //the array of queues
  int totalItems;
};

//Constructor for the queue array.  It sets the default size
//to 10, initializes the private variables size and totalItems
template <class QueueType>
QueueArray<QueueType>::QueueArray(int numOfQueue = 10):numOfQueues(numOfQueue),totalItems(0)
{
  arrayOfQueues = new std::queue<QueueType>[numOfQueue];
  if (arrayOfQueues == NULL)
  {
    cout << "Not enough memory to create the array" << endl;
    exit(-1);
  }
}

template <class QueueType>
QueueArray<QueueType>::~QueueArray()
{
}


//come back to this one
template <class QueueType>
int QueueArray<QueueType>::Enqueue(const QueueType &item, const int index)
{
  if (numOfQueues <= index || index < 0)
  {
    return -1;
  }
  else
  {
    arrayOfQueues[index].push(item);
    totalItems++;
    // if this works need to figure out bool for this
    return 1;
  }
}

template <class QueueType>
QueueType QueueArray<QueueType>::Dequeue()
{
  QueueType dequeuedItem;
  for (int i = 0; i < numOfQueues; i++)
  {
    if (!arrayOfQueues[i].empty())
    {
      dequeuedItem = arrayOfQueues[i].front();
      arrayOfQueues[i].pop();
      totalItems--;
      break;
    }
  }
  //need to check if an item was dequeued
  return dequeuedItem;
  return 0;
}

template <class QueueType>
int QueueArray<QueueType>::Qsize(int index)
{
  if (numOfQueues <= index || index < 0)
  {
    return -1;
  }
  else
  {
    return arrayOfQueues[index].size();
  }
}

template <class QueueType>
int QueueArray<QueueType>::Asize()
{
  return numOfQueues;
}

template <class QueueType>
int QueueArray<QueueType>::QAsize()
{
  return totalItems;
}

template <class QueueType>
QueueType* QueueArray<QueueType>::Qstate(int index)
{
  //if (numOfQueues <= index || index < 0)
  //{
  //  return NULL;
  //}
  //else
  //{
  //  QueueType returnArray[arrayOfQueues[index].size()];
  //  while (!arrayOfQueues[index].empty())
  //  {
  //    returnArrray[]
  //  }
  //}
  return NULL;
}
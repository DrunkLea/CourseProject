#include <iostream>
#include "json.hpp"

#include "priorityqueue.h"
using namespace std;

PriorityQueue::PriorityQueue(std::size_t max_size) :
	nodes_(max_size + 1, KeyValuePair()),
	max_size_(max_size),
	size_(0) {
}

void PriorityQueue::insert(Key k) {
	insert(std::make_pair(k, std::make_pair(0, 0)));
}

void PriorityQueue::insert(KeyValuePair kv) {

	nodes_[++size_]=kv;
	heapifyUp(size_);
}

KeyValuePair PriorityQueue::min() {
	// TODO: complete this function
	return nodes_[ROOT];
}

KeyValuePair PriorityQueue::removeMin() {
	KeyValuePair min = nodes_[ROOT];
	removeNode(1);
	return min;
}

bool PriorityQueue::isEmpty() const {
	// TODO: complete this function
	return size_==0?true:false;
}

size_t PriorityQueue::size() const {
	// TODO: complete this function
	return size_;
}

nlohmann::json PriorityQueue::JSON() const {
	nlohmann::json result;
  for (size_t i = 1; i <= size_; i++) {
      nlohmann::json node;
      KeyValuePair kv = nodes_[i];
      node["key"] = kv.first;
      node["value"] = kv.second;
      if (i != ROOT) {
          node["parent"] = std::to_string(i / 2);
      }
      if (2 * i <= size_) {
          node["leftChild"] = std::to_string(2 * i);
      }
      if (2 * i + 1 <= size_) {
          node["rightChild"] = std::to_string(2 * i + 1);
      }
      result[std::to_string(i)] = node;
  }
  result["metadata"]["maxHeapSize"] = max_size_;
  result["metadata"]["size"] = size_;
	return result;
}

void PriorityQueue::heapifyUp(size_t i) {
	// TODO: complete this function
	while (i>1 && getKey(i) < getKey(i/2)) {
		size_t parent = i/2;
		KeyValuePair temp = nodes_[i];
		nodes_[i] = nodes_[parent];
		nodes_[parent] = temp;
		i = parent;
	}
}

void PriorityQueue::heapifyDown(size_t i) {
	// TODO: complete this function
	while (2*i<=size_) {
		size_t smallerChildIndex;
		if (2*i+1<=size_ && getKey(2*i+1) < getKey(2*i)) {
			smallerChildIndex = 2*i+1;
		} else {
			smallerChildIndex = 2*i;
		}

		if (getKey(i) <= getKey(smallerChildIndex)) {
			break;
		} else {
			KeyValuePair temp = nodes_[i];
			nodes_[i]=nodes_[smallerChildIndex];
			nodes_[smallerChildIndex] = temp;
		}
		i = smallerChildIndex;
	}
}

void PriorityQueue::removeNode(size_t i) {
	// TODO: complete this function
	nodes_[i] = nodes_[size_];
	nodes_.pop_back();
	heapifyDown(i);
	size_--;
}

Key PriorityQueue::getKey(size_t i) {
	// TODO: complete this function
	KeyValuePair kv = nodes_[i];
	return kv.first;
}

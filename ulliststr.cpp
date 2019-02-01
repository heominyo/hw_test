#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(NULL == ptr){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(NULL == ptr){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(NULL == ptr){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

void ULListStr::push_back(const std::string& val){
	if(this->tail_ == NULL){
    Item* toAdd = new Item();
    this->head_ = toAdd;
    this->tail_ = toAdd;
  }
  Item* tail = this->tail_;
  if(tail->last >= (size_t)10){
    Item* toAdd = new Item();
    tail->next = toAdd;
    toAdd->prev = tail;
    this->tail_ = toAdd;
    tail = tail->next;
  }
  tail->val[(tail->last)++] = val;
  (this->size_)++;
}

void ULListStr::push_front(const std::string& val){
  if(this->head_ == NULL){
    Item* toAdd = new Item();
    this->head_ = toAdd;
    this->tail_ = toAdd;
  }
  Item* head = this->head_;
  if(head->first == (size_t)0){
    if(head->last == (size_t)0){
      push_back(val);
      return;
    }
    else{
      Item* toAdd = new Item();
      head->prev = toAdd;
      toAdd->next = head;
      this->head_ = toAdd;
      head = toAdd;
      head->first = (size_t)10;
      head->last = (size_t)10;
    }
  }
  head->val[--(head->first)] = val;
  (this->size_)++;
}

void ULListStr::pop_back(){
  
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  Item* toLook = this->head_;
  size_t iter = loc;
  while(true){
    if(toLook == NULL) return NULL;
    size_t numItems = toLook->last - toLook->first;
    if(numItems == 0) return NULL;
    else if(numItems <= iter){
      iter-=numItems;
      toLook = toLook->next;
    }
    else{
      break;
    }
  }
  return &(toLook->val[toLook->first+iter]);
}

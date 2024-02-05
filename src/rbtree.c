#include "rbtree.h"

#include <stdlib.h>

//2월 4일
rbtree *new_rbtree(void) 
{
  rbtree *p = (rbtree *)calloc(1, sizeof(rbtree));
  // TODO: initialize struct if needed
  return p;
}

void delete_rbtree(rbtree *t) 
{
  // TODO: reclaim the tree nodes's memory
  free(t);
}

node_t* rbtree_insert(rbtree *t, const key_t key) 
{
  // 새로운 노드에 메모리 할당
  node_t* new_node = (node_t*)malloc(sizeof(node_t));
  new_node->key = key;
  new_node->left = new_node->right = new_node->parent = t->nil;
  new_node->color = RBTREE_RED;

  if(t->root == NULL)
  {
    new_node->color = RBTREE_BLACK;
    t->root = new_node;
  }
  else
  {
    node_t* tmp = t->root;
    node_t* parent = NULL;

    while(tmp != t->nil)
    {
      parent = tmp;

      if(tmp->key > key)
      {
        tmp = tmp->left;
      }
      else if(tmp->key < key)
      {
        tmp = tmp->right;
      }
      else
      {
        // 이미 같은 키가 존재할 때의 처리
        free(new_node);
        return t->root;
      }
    }

    // 새로운 노드를 부모 노드와 연결
    new_node->parent = parent;

    // 부모 노드의 자식으로 새로운 노드 연결
    if (parent->key > key)
    {
      parent->left = new_node;
    }
    else
    {
      parent->right = new_node;
    }
    rbtree_insert_fixup(t, new_node);
  }

  return t->root;
}

node_t *rbtree_find(const rbtree *t, const key_t key) 
{
  // TODO: implement find
  return t->root;
}

node_t *rbtree_min(const rbtree *t) 
{
  // TODO: implement find
  node_t* tmp = t->root;
  while(tmp->left != t->nil)
  {
    tmp = tmp->left;
    return tmp;
  }
  return tmp;
}

node_t *rbtree_max(const rbtree *t) 
{
  node_t* tmp = t->root;
  while(tmp->right != t->nil)
  {
    tmp = tmp->right;
    return tmp;
  }
  return tmp;
}

int rbtree_erase(rbtree *t, node_t *p) 
{
  // TODO: implement erase
  return 0;
}

//2월 4일
int rbtree_to_array(const rbtree *t, key_t *arr, const size_t n) 
{
  // TODO: implement to_array
  return 0;
}

void insert_fixup(rbtree *t, node_t *x) 
{
  while (x->parent && x->parent->color == RBTREE_RED) 
  {
    if (x->parent == x->parent->parent->left) 
    {
      node_t *y = x->parent->parent->right;
      if (y && y->color == RBTREE_RED) 
      {
        x->parent->color = RBTREE_BLACK;
        y->color = RBTREE_BLACK;
        x->parent->parent->color = RBTREE_RED;
        x = x->parent->parent;
      } 
      else 
      {
        if (x == x->parent->right) 
        {
          x = x->parent;
          // 왼쪽 회전
        }
        x->parent->color = RBTREE_BLACK;
        x->parent->parent->color = RBTREE_RED;
        // 오른쪽 회전
      }
    } 
    else 
    {
      // x->parent가 부모의 오른쪽 자식인 경우에 대한 처리
    }
  }
  t->root->color = RBTREE_BLACK;
}



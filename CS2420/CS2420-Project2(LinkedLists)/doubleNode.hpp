//
//  doubleNode.hpp
//  CS2420-Project2
//
//  Created by Riley Stahura on 1/30/19.
//  Copyright © 2019 Riley Stahura. All rights reserved.
//

#ifndef doubleNode_hpp
#define doubleNode_hpp

typedef int node_entry;
#include <stdio.h>
struct doubleNode
{
    doubleNode();
    doubleNode(node_entry num, doubleNode *previous = NULL, doubleNode *follow = NULL);
    
    node_entry data;
    doubleNode *llink;
    doubleNode *next;
};

doubleNode::doubleNode()
{
    llink = NULL;
    next = NULL;
}
doubleNode::doubleNode(node_entry num, doubleNode *previous, doubleNode *follow)
{
    data = num;
    llink = previous;
    next = follow;
}
#endif /* doubleNode_hpp */

// Arc Activities Plugin.  Copyright Puny Human and Garrett Fleenor.  Licensed under MIT or Apache 2.0 license.  See LICENSE-MIT and LICENSE-APACHE for more info


#pragma once

#include "CoreMinimal.h"

extern const float GRID_SNAP;

class UEdGraphNode;

class FNodeVisitorCycleChecker
{
public:
	/** Check whether a loop in the graph would be caused by linking the passed-in nodes */
	bool CheckForLoop(UEdGraphNode* StartNode, UEdGraphNode* EndNode);

private:
	/**
	 * Helper function for CheckForLoop()
	 * @param	Node	The node to start traversal at
	 * @return true if we reached a root node (i.e. a node with no input pins), false if we encounter a node we have already seen
	 */
	bool TraverseInputNodesToRoot(UEdGraphNode* Node);

	TSet<UEdGraphNode*> VisitedNodes;
};
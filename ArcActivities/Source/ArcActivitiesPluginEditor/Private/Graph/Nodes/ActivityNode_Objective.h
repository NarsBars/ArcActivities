// Arc Activities Plugin.  Copyright Puny Human and Garrett Fleenor.  Licensed under MIT or Apache 2.0 license.  See LICENSE-MIT and LICENSE-APACHE for more info


#pragma once

#include "ActivityNode_Base.h"
#include "ActivityNode_Objective.generated.h"

class UArcActivityObjective;

UCLASS()
class UActivityNode_Objective : public UActivityNode_Base
{
	GENERATED_BODY()
public:
	UActivityNode_Objective(const FObjectInitializer& ObjectInitializer);

	virtual void AllocateDefaultPins() override;
	virtual void GetNodeContextMenuActions(class UToolMenu* Menu, class UGraphNodeContextMenuContext* Context) const override;
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual FText GetDescription() const;

	UArcActivityObjective* GetObjective() const;

	void CreateAddTrackerSubMenu(class FMenuBuilder& MenuBuilder, UEdGraph* Graph) const;
	void AddContextMenuActionsTracker(class UToolMenu* Menu, class UGraphNodeContextMenuContext* Context) const;

	virtual void OnSubNodeAdded(UAIGraphNode* SubNode);
	virtual void OnSubNodeRemoved(UAIGraphNode* SubNode);
};
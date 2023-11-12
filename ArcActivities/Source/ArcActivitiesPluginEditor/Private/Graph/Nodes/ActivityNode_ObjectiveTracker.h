// Arc Activities Plugin.  Copyright Puny Human and Garrett Fleenor.  Licensed under MIT or Apache 2.0 license.  See LICENSE-MIT and LICENSE-APACHE for more info


#pragma once

#include "ActivityNode_Base.h"
#include "ActivityNode_ObjectiveTracker.generated.h"

class UArcActivityTask_ObjectiveTracker;;

UCLASS()
class UActivityNode_ObjectiveTracker : public UActivityNode_Base
{
	GENERATED_BODY()
public:
	UActivityNode_ObjectiveTracker(const FObjectInitializer& ObjectInitializer);

	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual FText GetDescription() const;
	virtual void AllocateDefaultPins() override;

	UArcActivityTask_ObjectiveTracker* GetObjectiveTracker();

};
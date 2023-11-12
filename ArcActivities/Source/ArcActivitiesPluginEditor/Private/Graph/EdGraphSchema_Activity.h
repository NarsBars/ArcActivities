// Arc Activities Plugin.  Copyright Puny Human and Garrett Fleenor.  Licensed under MIT or Apache 2.0 license.  See LICENSE-MIT and LICENSE-APACHE for more info


#pragma once

#include "EdGraph/EdGraphSchema.h"
#include "ActivityEditorTypes.h"
#include "AIGraphSchema.h"
#include "EdGraphSchema_Activity.generated.h"


class UActivityNode_Base;

UCLASS()
class UEdGraphSchema_Activity : public UAIGraphSchema
{
	GENERATED_BODY()
public:
	UEdGraphSchema_Activity(const FObjectInitializer& ObjectInitializer);
	   

	// Begin EdGraphSchema interface
	virtual void GetGraphContextActions(FGraphContextMenuBuilder& ContextMenuBuilder) const override;
	virtual FLinearColor GetPinTypeColor(const FEdGraphPinType& PinType) const override;
	virtual bool TryCreateConnection(UEdGraphPin* A, UEdGraphPin* B) const override;
	virtual const FPinConnectionResponse CanCreateConnection(const UEdGraphPin* A, const UEdGraphPin* B) const override;
	// End EdGraphSchema interface

	virtual void GetArcSubNodeClasses(int32 SubNodeFlags, TArray<FArcGraphNodeClassData>& ClassData, UClass*& GraphNodeClass) const;

	virtual void GetGraphNodeContextActions(FGraphContextMenuBuilder& ContextMenuBuilder, int32 SubNodeFlags) const override;


};


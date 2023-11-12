// Arc Activities Plugin.  Copyright Puny Human and Garrett Fleenor.  Licensed under MIT or Apache 2.0 license.  See LICENSE-MIT and LICENSE-APACHE for more info


#include "ActivityNode_Service.h"
#include "DataModel/ArcActivityTask_StageService.h"

UActivityNode_Service::UActivityNode_Service(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

FText UActivityNode_Service::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	FString StoredClassName = ClassData.GetClassName();
	StoredClassName.RemoveFromEnd(TEXT("_C"));

	return FText::Format(NSLOCTEXT("ActivityClass", "ObjectiveTrackerString", "Service {0}"), FText::FromString(StoredClassName));

}

void UActivityNode_Service::AllocateDefaultPins()
{
	//No Pins
}

UArcActivityTask_StageService* UActivityNode_Service::GetService()
{
	return Cast<UArcActivityTask_StageService>(GetNodeInstance());
}

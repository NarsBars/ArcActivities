// Arc Activities Plugin.  Copyright Puny Human and Garrett Fleenor.  Licensed under MIT or Apache 2.0 license.  See LICENSE-MIT and LICENSE-APACHE for more info


#include "Factory_ObjectiveTracker.h"
#include "DataModel/ArcActivityTask_ObjectiveTracker.h"


UFactory_ObjectiveTracker::UFactory_ObjectiveTracker(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UArcActivityTask_ObjectiveTracker::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}

UObject* UFactory_ObjectiveTracker::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return NewObject<UArcActivityTask_ObjectiveTracker>(InParent, Class, Name, Flags);
}

bool UFactory_ObjectiveTracker::CanCreateNew() const
{
	return true;
}

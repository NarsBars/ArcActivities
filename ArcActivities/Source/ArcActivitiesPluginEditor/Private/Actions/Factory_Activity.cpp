// Arc Activities Plugin.  Copyright Puny Human and Garrett Fleenor.  Licensed under MIT or Apache 2.0 license.  See LICENSE-MIT and LICENSE-APACHE for more info


#include "Factory_Activity.h"
#include "DataModel/ArcActivity.h"


UFactory_Activity::UFactory_Activity(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UArcActivity::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}

UObject* UFactory_Activity::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return NewObject<UArcActivity>(InParent, Class, Name, Flags);
}

bool UFactory_Activity::CanCreateNew() const
{
	return true;
}

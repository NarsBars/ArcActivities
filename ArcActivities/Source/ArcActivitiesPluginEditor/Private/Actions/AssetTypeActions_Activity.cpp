// Arc Activities Plugin.  Copyright Puny Human and Garrett Fleenor.  Licensed under MIT or Apache 2.0 license.  See LICENSE-MIT and LICENSE-APACHE for more info


#include "AssetTypeActions_Activity.h"
#include "DataModel/ArcActivity.h"

#include "ActivityEditor.h"
#include "ActivitiesPluginEditorModule.h"

#define LOCTEXT_NAMESPACE "ActivitiesPlugin"

FAssetTypeActions_Activity::FAssetTypeActions_Activity(EAssetTypeCategories::Type InAssetCategory)
	: AssetCategory(InAssetCategory)
{

}

FText FAssetTypeActions_Activity::GetName() const
{
	return LOCTEXT("AssetTypeAction_Activity", "Activity");
}

FColor FAssetTypeActions_Activity::GetTypeColor() const
{
	return FColor::Emerald;
}

UClass* FAssetTypeActions_Activity::GetSupportedClass() const
{
	return UArcActivity::StaticClass();
}

void FAssetTypeActions_Activity::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor /*= TSharedPtr<IToolkitHost>()*/)
{
	const EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;

	for (UObject* Object : InObjects)
	{
		if (UArcActivity* Activity = Cast<UArcActivity>(Object))
		{
			FActivityEditor* ExistingInstance = static_cast<FActivityEditor*>(GEditor->GetEditorSubsystem<UAssetEditorSubsystem>()->FindEditorForAsset(Object, false));
			if (ExistingInstance)
			{
				ExistingInstance->InitActivityEditor(Mode, EditWithinLevelEditor, Activity);
			}
			else
			{
				FActivitiesPluginEditorModule& Module = FModuleManager::GetModuleChecked<FActivitiesPluginEditorModule>(TEXT("ArcActivitiesPluginEditor"));
				TSharedRef<FActivityEditor> NewEditor = Module.CreateActivityEditor(Mode, EditWithinLevelEditor, Activity);
			}						 									
		}
	}
}

uint32 FAssetTypeActions_Activity::GetCategories()
{
	return AssetCategory;
}

#undef LOCTEXT_NAMESPACE

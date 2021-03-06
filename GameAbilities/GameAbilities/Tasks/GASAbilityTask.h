#pragma once
#include "GameplayTask.h"
#include "../GASAbilityBase.h"
#include "../GASAbilitiesComponent.h"
#include "GASAbilityTask.generated.h"
/*
	AbilityActions are generic (preferably C++) defined actions, which then can be added to ability and
	the should be activated from ability. 
	Then can perform tasks, like spawn tagetting helpers (splines, circles), spawn actors, 
	gather targeting data etc.

	Should they be activated automatically after ability is initialized, (it'e ability enterted in
	active state, which means it's ready to be fired and display helpers, but did not yet received input,
	or should designer in blueprint decide when to launch actions ?).
*/
UCLASS(BlueprintType, Blueprintable, Within=GASAbilityBase)
class GAMEABILITIES_API UGASAbilityTask : public UGameplayTask
{
	GENERATED_UCLASS_BODY()
public:
	/* Ability owning this task */
	TWeakObjectPtr<UGASAbilityBase> Ability;
	/* Ability owning this task */
	TWeakObjectPtr<UGASAbilitiesComponent> AbilityComponent;
public:
	//virtual UWorld* GetWorld() const override;

	//virtual void Tick(float DeltaSecondsIn);

	virtual void Initialize();
	template <class T>
	static T* NewAbilityTask(UObject* WorldContextObject, FName InstanceName = FName())
	{
		check(WorldContextObject);

		T* MyObj = NewObject<T>(WorldContextObject);
		UGASAbilityBase* ThisAbility = CastChecked<UGASAbilityBase>(WorldContextObject);
		MyObj->InitTask(*ThisAbility, ThisAbility->GetDefaultPriority());
		MyObj->InstanceName = InstanceName;
		MyObj->AbilityComponent = ThisAbility->AbilityComponent;
		return MyObj;
	}

	template<typename T>
	static bool DelayedFalse()
	{
		return false;
	}

	// this function has been added to make sure AbilityTasks don't use this method
	template <class T>
	FORCEINLINE static T* NewTask(UObject* WorldContextObject, FName InstanceName = FName())
	{
		static_assert(DelayedFalse<T>(), "UAbilityTask::NewTask should never be used. Use NewAbilityTask instead");
	}
};

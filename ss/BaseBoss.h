// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BattleBase.h"
#include "BossEnum.h"
#include "BaseBoss.generated.h"

/**
 * 
 */
UCLASS()
class TPSGAME_API ABaseBoss : public ABattleBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABaseBoss();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	void HandleBossDeath();
	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;


public:
	//HP -> BattleBase.h
		// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	float m_BossMaxHealth = 1000.f;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void OnSimpleAttack();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void OnRangedSkill1();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void OnRangedSkill2();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void OnRangedSkill3();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void OnMeleeSkill1();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void OnMeleeSkill2();

	UFUNCTION(BlueprintCallable)
	void BosscoolTimeReset();

};

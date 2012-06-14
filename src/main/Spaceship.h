#ifndef THE_DARK_CRYSTAL_PLAIN
#define THE_DARK_CRYSTAL_PLAIN

#include "Vehicle.h"

/**
  * ��Ϸ�ؾ�֮һ������ɴ���
  */
class Spaceship : public Vehicle {

	Q_OBJECT

public:

	/**
	  * ���캯��
	  * @param node_name Node�ڵ�����
	  * @param mesh_handle ģ�;��
	  * @param collision_shape_type ��������
	  * @param mass �ؾ�����
	  * @param attack_value �ؾ߹�����
	  * @param attack_range �ؾ߹�����Χ
	  * @param attack_interval �ؾ߹���ʱ����
	  * @param attack_sound_handle �ؾ߹����������
	  * @param flying_sound_handle �ɴ������������
	  * @param rise_sound_handle �ɴ������������
	  * @param fall_sound_handle �ɴ��½��������
	  */
	Spaceship(const QString node_name, 
		  const QString mesh_handle, 
	      const dt::PhysicsBodyComponent::CollisionShapeType collision_shape_type, 
		  const btScalar mass,
		  const uint16_t attack_value,
		  const float attack_range,
		  const float attack_interval,
		  const QString attack_sound_handle,
		  const QString flying_sound_handle,
		  const QString rise_sound_handle,
		  const QString fall_sound_handle
		  );

	void onInitialize();

	void onDeinitialize();

protected slots:
	void __onMove(MoveType type, bool is_pressed);

	/**
	  * �����SpeedUp������Ϊ�ɻ����½�
	  */
    void __onSpeedUp(bool is_pressed);

    void __onLookAround(Ogre::Quaternion quaternion);


protected:
	QString mFlyingSoundHandle;             //!< �ɻ������������
	QString mRiseSoundHandle;               //!< �ɻ������������
	QString mFallSoundHandle;               //!< �ɻ��½��������

	const static QString FLYING_SOUND_COMPONENT;   //!< �ɻ���������Component������
	const static QString RISE_SOUND_COMPONENT;     //!< �ɻ���������Component������
	const static QString FALL_SOUND_COMPONENT;     //!< �ɻ��½�����Component������
};

#endif
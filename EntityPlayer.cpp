#include "EntityPlayer.h"

EntityPlayer::EntityPlayer(TypePlayer playerType)
{
	position = playerType.startPos;
	rotation = playerType.rotation;
	acceleration = playerType.acceleration;
	maxSpeed = playerType.maxSpeed;
	size = playerType.size;
	texture = playerType.texture;
	
	online = false;
	bb = new RectangleShape(new glm::vec2(0, 0), 0.0, new glm::vec2(playerType.size.x, playerType.size.y/4)); //TODO BOUNDINGBOXES
	
	inventoryOpen = false;

}

EntityPlayer::~EntityPlayer(void)
{
	inventory.reset();
}

void EntityPlayer::setInventory(std::shared_ptr<Inventory> inv)
{
	inventory = inv;
}

void EntityPlayer::toggleInventory(void)
{
	inventoryOpen = !inventoryOpen;
}

void EntityPlayer::update(float delta, const Uint8* keyCode)
{
	if(keyCode[SDL_SCANCODE_W])
		velocity.y += acceleration;
	if(keyCode[SDL_SCANCODE_S])
		velocity.y -= acceleration;
	if(keyCode[SDL_SCANCODE_A])
		velocity.x -= acceleration;
	if(keyCode[SDL_SCANCODE_D])
		velocity.x += acceleration;

	if(abs(velocity.x) > maxSpeed)
	{
		if(velocity.x > 0)
			velocity.x = maxSpeed;
		else if(velocity.x < 0)
			velocity.x = -maxSpeed;
	}

	if(abs(velocity.y) > maxSpeed)
	{
		if(velocity.y > 0)
			velocity.y = maxSpeed;
		else if(velocity.y < 0)
			velocity.y = -maxSpeed;
	}

	if(!keyCode[SDL_SCANCODE_A] && !keyCode[SDL_SCANCODE_D])
	{
		if(velocity.x > 0)
			velocity.x -= friction*delta;
		else if(velocity.x < 0)
			velocity.x += friction*delta;
	}

	if(!keyCode[SDL_SCANCODE_W] && !keyCode[SDL_SCANCODE_S])
	{
		if(velocity.y > 0)
			velocity.y -= friction*delta;
		else if(velocity.y < 0)
			velocity.y += friction*delta;
	}

	if(abs(velocity.x) < 0.5)
		velocity.x = 0;

	if(abs(velocity.y) < 0.5)
		velocity.y = 0;
	
	position.x += velocity.x * delta;
	position.y += velocity.y * delta;
}

void EntityPlayer::updateNoKey(float delta)
{
	if(abs(velocity.x) > maxSpeed)
	{
		if(velocity.x > 0)
			velocity.x = maxSpeed;
		else if(velocity.x < 0)
			velocity.x = -maxSpeed;
	}

	if(abs(velocity.y) > maxSpeed)
	{
		if(velocity.y > 0)
			velocity.y = maxSpeed;
		else if(velocity.y < 0)
			velocity.y = -maxSpeed;
	}

	if(velocity.x > 0)
		velocity.x -= friction*delta;
	else if(velocity.x < 0)
		velocity.x += friction*delta;


	if(velocity.y > 0)
		velocity.y -= friction*delta;
	else if(velocity.y < 0)
		velocity.y += friction*delta;

	if(abs(velocity.x) < 0.5)
		velocity.x = 0;

	if(abs(velocity.y) < 0.5)
		velocity.y = 0;
	
	position.x += velocity.x * delta;
	position.y += velocity.y * delta;
}

glm::vec2 EntityPlayer::getCenterPosition(void)
{
	return glm::vec2(position.x + bb->getWidth()/2, position.y + bb->getHeight()/2);
}

void EntityPlayer::setId(int idIn)
{
	id = idIn;
	online = true;
}

int EntityPlayer::getId(void)
{
	return id;
}

bool EntityPlayer::isOnline(void)
{
	return online;
}

glm::vec2 EntityPlayer::getSize(void)
{
	return size;
}

RectangleShape* EntityPlayer::getBB(void)
{
	return bb;
}

std::string EntityPlayer::getTexture(void)
{
	return texture;
}

void EntityPlayer::setFriction(float frictionIn)
{
	friction = frictionIn;
}

bool EntityPlayer::hasInventoryOpen(void)
{
	return inventoryOpen;
}

std::shared_ptr<Inventory> EntityPlayer::getInventory(void)
{
	return inventory;
}
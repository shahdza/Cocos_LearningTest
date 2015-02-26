
-- 继承LayerColor类
GameLayer = class("GameLayer", function()
	return cc.LayerColor:create(cc.c4b(255,255,255,255))
end)


-- 初始化函数 ， 这里我仅声明一些变量
function GameLayer:ctor()
	self.heroCount = 0      -- 英雄个数
	self.hero = {}          -- 英雄集合
end


-- 提供创建包含GameLayer层的Scene
function GameLayer:createScene(heroCount)
	local scene = cc.Scene:createWithPhysics()          -- 物理世界
	scene:getPhysicsWorld():setGravity(cc.p(0, -1000))  -- 重力
	local layer = GameLayer:create(heroCount)           -- 创建GameLayer层
	scene:addChild(layer)
	return scene
end


-- 创建GameLayer层
function GameLayer:create(heroCount)
	local layer = GameLayer.new()   -- 创建GameLayer类
	layer:init(heroCount)           -- 自定义初始化
	return layer
end


-- 自定义初始化 init
function GameLayer:init(heroCount)

	self.heroCount = heroCount
	self:addHero()  -- 在GameLayer层上添加Hero精灵
	
end


--------------------------------------------------------------------------------

-- 使用方法
	-- 创建一个包含GameLayer层的场景Scene
	GameLayer:createScene(heroCount)
	
	-- 创建一个GameLayer层
	GameLayer:create(heroCount)





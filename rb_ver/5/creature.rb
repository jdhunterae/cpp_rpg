class Creature
  attr_accessor :name, :className
  attr_accessor :str, :con, :dex, :health, :healthMax, :hitRate
  attr_accessor :level, :exp
  attr_accessor :inventory, :equippedWeapon, :equippedArmour

  def initialize
    @inventory = Inventory.new
    @equippedWeapon = nil
    @equippedArmour = array(3)

    @level = 1
    @exp = 0
  end

  def initialize(name, health, str, con, dex, hitRate, level, className)
    @name = name
    @health = health
    @healthMax = health
    @str = str
    @con = con
    @dex = dex
    @hitRate = hitRate
    @className = className || ""

    @inventory = Inventory.new
    @equippedWeapon = nil
    @equippedArmour = [nil, nil, nil]

    @level = level || 1
    @exp = 0
  end

  def expToLevel(level)
    return 128 * level * level
  end

  def levelUp
    if (@exp >= expToLevel(@level + 1))
      @level += 1

      healthBoost = 0
      strBoost = 0
      conBoost = 0
      dexBoost = 0

      if (@level % 3 == 0)
        healthBoost = 10 + (rand(0...4)) + @con / 4
      else
        healthBoost = @con / 4
      end

      if (@className == "Fighter")
        strBoost = 1
        conBoost = 1
        dexBoost = 1 if (rand(0...2) == 0)
      elsif (@className == "Rogue")
        strBoost = 1 if (rand(0...2) == 0)
        conBoost = 1
        dexBoost = 1
      end

      @healthMax += healthBoost
      @health += healthBoost
      @str += strBoost
      @con += conBoost
      @dex += dexBoost

      puts "#{@name} grew to level #{@level}!"
      puts "Health:  +#{healthBoost} -> #{@healthMax}"
      puts "STR:     +#{strBoost} -> #{@str}"
      puts "CON:     +#{conBoost} -> #{@con}"
      puts "DEX:     +#{dexBoost} -> #{@dex}"
      puts "--------------------------"

      return true
    end

    return false
  end

  def equipWeapon(weapon)
    @equippedWeapon = weapon
  end

  def equipArmour(armour)
    @equippedArmour[armour.slot] = armour
  end
end

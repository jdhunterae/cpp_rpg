require "./item.rb"


class Weapon < Item
  attr_accessor :damage, :hitRate

  def initialize; end

  def initialize(name, description, damage, hitRate)
    super(name, description)
    @damage = damage
    @hitRate = hitRate
  end

  def ==(another_weapon)
    return (
      super(another_weapon) &&
      (@damage == another_weapon.damage) &&
      (@hitRate == another_weapon.hitRate)
    )
  end

  def to_s
    "#{@name} : #{@description}\n\t+#{@damage} [#{@hitRate}]"
  end
end

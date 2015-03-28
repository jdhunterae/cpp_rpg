require "./item.rb"


class Weapon < Item
  @damage = 0
  @hitRate = 0.0

  def initialize; end

  def initialize(name, description, damage, hitRate)
    super(name, description)
    @damage = damage
    @hitRate = hitRate
  end
end

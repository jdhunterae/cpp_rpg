require "./item.rb"


class Armour < Item
  class Slot
    @@HEAD = 0
    @@TORSO = 1
    @@LEGS = 2
    @@N = 3
  end

  @slot = nil
  @defense = 0

  def initialize; end

  def initialize(name, description, defense, slot)
    super(name, description)
    @defense = defense
    @slot = slot
  end
end

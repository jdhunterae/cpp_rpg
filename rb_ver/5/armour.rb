require "./item.rb"


class Armour < Item
  attr_accessor :slot, :defense

  class Slot
    HEAD = 0
    TORSO = 1
    LEGS = 2
    N = 3

    def self.get(slot)
      case slot
      when HEAD
        return "HEAD"
      when TORSO
        return "TORSO"
      when LEGS
        return "LEGS"
      else
        return 3
      end
    end
  end

  def initialize; end

  def initialize(name, description, defense, slot)
    super(name, description)
    @defense = defense
    @slot = slot
  end

  def ==(another_armour)
    return (
      super(another_armour) &&
      (@slot == another_armour.slot) &&
      (@defense == another_armour.defense)
    )
  end

  def to_s
    "#{@name} [#{Armour::Slot::get(@slot)}] : #{@description}\n\t+#{@defense}"
  end
end

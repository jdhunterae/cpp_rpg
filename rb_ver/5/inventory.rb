require "./item.rb"
require "./weapon.rb"
require "./armour.rb"


class Inventory
  attr_accessor :items, :weapons, :armour

  class Couple
    attr_accessor :obj, :num
    def initialize(obj, num)
      @obj = obj
      @num = num
    end
  end

  def initialize
    @items = []
    @weapons = []
    @armour = []
  end

  def initialize(items, weapons, armour)
    @items = items
    @weapons = weapons
    @armour = armour
  end

  def clear
    @items = []
    @weapons = []
    @armour = []
  end

  def add_item(item, count)
    @items.each do |it|
      if (it.obj == item)
        it.num += count
        return
      end
    end

    @items.push(Couple.new(item, count))
  end

  def remove_item(item, count)
    @items.each do |it|
      it.num -= count if (it.obj == item)
    end

    @items.delete_if { |it| it.num <= 0 }
  end

  def add_weapon(weapon, count)
    @weapons.each do |it|
      if (it.obj == weapon)
        it.num += count
        return
      end
    end

    @weapons.push(Couple.new(weapon, count))
  end

  def remove_weapon(weapon, count)
    @weapons.each do |it|
      it.num -= count if (it.obj == weapon)
    end

    @weapons.delete_if { |it| it.num <= 0 }
  end

  def add_armour(armour, count)
    @armour.each do |it|
      if (it.obj == armour)
        it.num += count
        return
      end
    end

    @armour.push(Couple.new(armour, count))
  end

  def remove_armour(armour, count)
    @armour.each do |it|
      it.num -= count if (it.obj == armour)
    end

    @armour.delete_if { |it| it.num <= 0 }
  end

  def merge(inventory)
    unless (inventory == self)
      inventory.items.each do |it|
        self.add_item(it.obj, it.num)
      end

      inventory.weapons.each do |it|
        self.add_weapon(it.obj, it.num)
      end

      inventory.armour.each do |it|
        self.add_armour(it.obj, it.num)
      end
    end
  end

  def print_items(label)
    label = label || false
    i = 1

    @items.each do |it|
      disp = ""
      disp += "#{i}: " if (label)
      disp += "#{it.obj.name} (#{it.num}) - #{it.obj.description}"
      puts disp
      i += 1
    end

    return @items.length
  end

  def print_weapons(label)
    label = label || false
    i = 1

    @weapons.each do |it|
      disp = ""
      disp += "#{i}: " if (label)
      disp += "#{it.obj.name} [+#{it.obj.damage} / #{it.obj.hitRate}] (#{it.num}) - #{it.obj.description}"
      puts disp
      i += 1
    end

    return @weapons.length
  end

  def print_armour(label)
    label = label || false
    i = 1

    @armour.each do |it|
      disp = ""
      disp += "#{i}: " if (label)
      disp += "#{it.obj.name} [+#{it.obj.defense} / #{Armour::Slot::get(it.obj.slot)}] (#{it.num}) - #{it.obj.description}"
      puts disp
      i += 1
    end

    return @armour.length
  end

  def print(label)
    label = label || false
    if ((@items.length + @weapons.length + @armour.length) > 0)
      print_items(label)
      print_weapons(label)
      print_armour(label)
    else
      puts "Nothing"
    end
  end
end

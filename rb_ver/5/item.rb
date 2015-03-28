class Item
  attr_accessor :name, :description

  def initialize; end

  def initialize(name, description)
    @name = name
    @description = description
  end

  def ==(another_item)
    return (
      (@name == another_item.name) &&
      (@description == another_item.description)
    )
  end

  def to_s
    "#{@name} : #{@description}"
  end
end

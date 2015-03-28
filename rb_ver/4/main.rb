require "./dialogue.rb"
require "./item.rb"
require "./creature.rb"


def main
  player = nil

  result = Dialogue.new(
    "Welcome!",
    ["New Game"]).activate()

  case result
    when 1
      player = dialogue_newchar
      puts "#{player.name} :: [LV #{player.level}] #{player.className}"
    else
      return 0
  end

  i = 0
  while (i <= 10)
    i += 1
    if (player.health <= 0)
      puts "\t----YOU DIED----"
      puts "\t    GAME OVER"
      return 0
    end
  end

  puts "\t----YOU LIVED----"
  puts "\t    GAME OVER"
  return 0
end

def dialogue_newchar
  puts "Choose your name"
  name = gets.chomp

  result = Dialogue.new(
    "Choose your class",
    ["Fighter", "Rogue"]).activate()

  case result
  when 1
    return Creature.new(name, 35, 20, 10, 5, 10.0, 1, "Fighter")
  when 2
    return Creature.new(name, 30, 5, 10, 20, 15.0, 1, "Rogue")
  else
    return Creature.new(name, 30, 10, 10, 10, 10.0, 1, "Adventurer")
  end
end


main

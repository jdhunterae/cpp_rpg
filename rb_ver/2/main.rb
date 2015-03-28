require "./dialogue.rb"
require "./creature.rb"


def main()
  result = Dialogue.new(
    "Choose your class",
    ["Fighter", "Rogue"]).activate()

  case result
    when 1
      puts "You chose 'Fighter'"
    when 2
      puts "You chose 'Rogue'"
    else
      puts "Dialogue is broken"
  end

  return 0
end


main

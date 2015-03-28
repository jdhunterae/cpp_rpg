class Dialogue
  @description = ""
  @choices = []

  def initialize(); end

  def initialize(description, choices)
    @description = description
    @choices = choices
  end

  def activate()
    puts @description

    i = 0
    @choices.each do |choice|
      puts "#{i+1}: #{choice}"
      i += 1
    end

    userInput = -1

    while (true)
      userInput = gets.chomp.to_i
      if (userInput >= 0 && userInput <= @choices.length)
        return userInput
      end

      puts "Please choose again"
    end

    return 0
  end
end

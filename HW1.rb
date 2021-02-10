#Matthew McCormack
#HW1 CS3060
#Jan/26/2021


def function1
    puts "Please enter 4 lines for text file"
    aFile = File.new("savedText.txt","w")
    
    line1 = gets
    aFile.write(line1)
    line2 = gets
    aFile.write(line2)
    line3 = gets
    aFile.write(line3)
    line4 = gets
    aFile.write(line4)

    aFile.close
    fileData = File.new("savedText.txt", "r")  # Get all the words in the file and count them    
    word_count = fileData.read.split.length # Output the word count in the file    
    puts "There are #{word_count} words in savedText.txt"
end

def function2
    puts 'Please type the name of a file'
    fn = gets
    fn = fn.strip # note that strip will get read of the newline character
    x = /Java|Hashkell|java|hashkell/
    y = /Python|Ruby|ruby|python/
    aFile = File.new("#{fn}", "r")
    aFile.each{|z|
        if z =~ x
            puts 'The file is not important'
        elsif z =~ y
            puts 'The file is superb'
            else
                puts 'The file is uninteresting'
            end
    }
    aFile.close
end

def function3
    n = 2
    while n <= 11
        x = 1
        y = 0
        while y < n
        x = x * n
        y +=1
        end
        puts "The #{n}-th power of integer #{n} is #{x}"
        n = n+1
    end
end

def function4    
    puts "Enter a number from 50 to 100"
	line = gets
	num = line.to_i
	head = 0
	tails = 0
	toss=[num]
	x = 0
	if (num >= 50 || num <= 100)
		until(x == num-1) do
		toss[x] = rand(0..2)
		x = x+1
		end
	else
		puts "I said 50 - 100, try again. Bye"
		SystemExit
	end
	for a in 0..x do
    if (toss[a] == 1)
        tails = tails +1
		else
		head = head+1
		end
    end
    ratio = (head.to_f/tails.to_f)
	puts "Heads: #{head}"
    puts "Tails: #{tails}"
    puts "Ratio: #{ratio}"

end

def function5
    hash1 = parse("story1.txt")
    hash2 = parse("story2.txt")
    combined = hash1.merge(hash2)
    puts "Unique words in both is #{combined.size}."
end

def parse(story_name)
    h = Hash.new(0)
    s_count=0
    aFile = File.new(story_name, "r")
    aFile.each_line { |line|
        words = line.split
        words.each { |w|
            if h.has_key?(w)
                h[w] = h[w] + 1
                else
                    h[w] = 1
            end
            }
        }
    h = h.sort {|kv1,kv2| kv2[1]<=>kv1[1]}
    key = h[2][0]
    value = h[2][1]
    h = h.to_h
    puts "--For #{story_name}--"
    puts "The third most frequent word is \"#{key}\" which is in the #{story_name} file #{value} times."
    puts "There are #{h.size} unique words in the #{story_name} file."
    h
end
function1
function2
function3
function4
function5

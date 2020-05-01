require './sock'

print("IP: ")
ip = gets.chomp
print("Range: ")
range = gets.chomp

i = 1

while i < range.to_i
    begin
        s = TCPSock(ip, i.to_s)
        puts "port #{i} -> open"
        i = i + 1
        
    rescue
        puts "port #{i} closed"
        i = i + 1
        
    end
    
end



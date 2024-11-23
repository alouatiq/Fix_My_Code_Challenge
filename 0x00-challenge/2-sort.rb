###
#
#  Sort integer arguments (ascending)
#
###

result = []

# Process each argument and add valid integers to the result array
ARGV.each do |arg|
  # Skip if not an integer
  next unless arg =~ /^-?\d+$/

  # Convert to integer and add to result
  result << arg.to_i
end

# Sort the result array in ascending order
result = result.sort

# Print the sorted integers
puts result

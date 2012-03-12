module SimpleEncode
	def self.encode(inArray)
		str = ''

		inArray.each_slice(7) { |items|
			extra = 0
			items.each_with_index { |item, i|
				extra += (item & 1) << (i+1)
			}
			str << extra
			items.each { |item| str << (item >> 1) }
		}

		return str
	end
end

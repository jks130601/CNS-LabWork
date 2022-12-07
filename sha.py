import hashlib

m = hashlib.sha512()
m.update(b"Send me $10000") #change message to what you want to encode
#If you want to use a variable use the other version of m.update()
variable = "Message"
m.update(variable.encode("utf8"))
hashedMessage = m.digest()
print(hashedMessage)
# from hashlib import sha512
# print(sha512('hello'.encode()).hexdigest())
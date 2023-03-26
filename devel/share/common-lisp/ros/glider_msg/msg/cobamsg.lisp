; Auto-generated. Do not edit!


(cl:in-package glider_msg-msg)


;//! \htmlinclude cobamsg.msg.html

(cl:defclass <cobamsg> (roslisp-msg-protocol:ros-message)
  ((a
    :reader a
    :initarg :a
    :type cl:integer
    :initform 0)
   (b
    :reader b
    :initarg :b
    :type cl:integer
    :initform 0)
   (c
    :reader c
    :initarg :c
    :type cl:float
    :initform 0.0)
   (kata
    :reader kata
    :initarg :kata
    :type cl:string
    :initform ""))
)

(cl:defclass cobamsg (<cobamsg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <cobamsg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'cobamsg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name glider_msg-msg:<cobamsg> is deprecated: use glider_msg-msg:cobamsg instead.")))

(cl:ensure-generic-function 'a-val :lambda-list '(m))
(cl:defmethod a-val ((m <cobamsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader glider_msg-msg:a-val is deprecated.  Use glider_msg-msg:a instead.")
  (a m))

(cl:ensure-generic-function 'b-val :lambda-list '(m))
(cl:defmethod b-val ((m <cobamsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader glider_msg-msg:b-val is deprecated.  Use glider_msg-msg:b instead.")
  (b m))

(cl:ensure-generic-function 'c-val :lambda-list '(m))
(cl:defmethod c-val ((m <cobamsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader glider_msg-msg:c-val is deprecated.  Use glider_msg-msg:c instead.")
  (c m))

(cl:ensure-generic-function 'kata-val :lambda-list '(m))
(cl:defmethod kata-val ((m <cobamsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader glider_msg-msg:kata-val is deprecated.  Use glider_msg-msg:kata instead.")
  (kata m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <cobamsg>) ostream)
  "Serializes a message object of type '<cobamsg>"
  (cl:let* ((signed (cl:slot-value msg 'a)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'b)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'c))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'kata))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'kata))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <cobamsg>) istream)
  "Deserializes a message object of type '<cobamsg>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'a) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'b) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'c) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'kata) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'kata) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<cobamsg>)))
  "Returns string type for a message object of type '<cobamsg>"
  "glider_msg/cobamsg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'cobamsg)))
  "Returns string type for a message object of type 'cobamsg"
  "glider_msg/cobamsg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<cobamsg>)))
  "Returns md5sum for a message object of type '<cobamsg>"
  "a436b8d370a26d189e735c968518dc40")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'cobamsg)))
  "Returns md5sum for a message object of type 'cobamsg"
  "a436b8d370a26d189e735c968518dc40")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<cobamsg>)))
  "Returns full string definition for message of type '<cobamsg>"
  (cl:format cl:nil "int32 a~%int32 b~%float32 c~%string kata~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'cobamsg)))
  "Returns full string definition for message of type 'cobamsg"
  (cl:format cl:nil "int32 a~%int32 b~%float32 c~%string kata~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <cobamsg>))
  (cl:+ 0
     4
     4
     4
     4 (cl:length (cl:slot-value msg 'kata))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <cobamsg>))
  "Converts a ROS message object to a list"
  (cl:list 'cobamsg
    (cl:cons ':a (a msg))
    (cl:cons ':b (b msg))
    (cl:cons ':c (c msg))
    (cl:cons ':kata (kata msg))
))

;; Auto-generated. Do not edit!


(when (boundp 'glider_msg::cobamsg)
  (if (not (find-package "GLIDER_MSG"))
    (make-package "GLIDER_MSG"))
  (shadow 'cobamsg (find-package "GLIDER_MSG")))
(unless (find-package "GLIDER_MSG::COBAMSG")
  (make-package "GLIDER_MSG::COBAMSG"))

(in-package "ROS")
;;//! \htmlinclude cobamsg.msg.html


(defclass glider_msg::cobamsg
  :super ros::object
  :slots (_a _b _c _kata ))

(defmethod glider_msg::cobamsg
  (:init
   (&key
    ((:a __a) 0)
    ((:b __b) 0)
    ((:c __c) 0.0)
    ((:kata __kata) "")
    )
   (send-super :init)
   (setq _a (round __a))
   (setq _b (round __b))
   (setq _c (float __c))
   (setq _kata (string __kata))
   self)
  (:a
   (&optional __a)
   (if __a (setq _a __a)) _a)
  (:b
   (&optional __b)
   (if __b (setq _b __b)) _b)
  (:c
   (&optional __c)
   (if __c (setq _c __c)) _c)
  (:kata
   (&optional __kata)
   (if __kata (setq _kata __kata)) _kata)
  (:serialization-length
   ()
   (+
    ;; int32 _a
    4
    ;; int32 _b
    4
    ;; float32 _c
    4
    ;; string _kata
    4 (length _kata)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _a
       (write-long _a s)
     ;; int32 _b
       (write-long _b s)
     ;; float32 _c
       (sys::poke _c (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; string _kata
       (write-long (length _kata) s) (princ _kata s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _a
     (setq _a (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _b
     (setq _b (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float32 _c
     (setq _c (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; string _kata
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _kata (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get glider_msg::cobamsg :md5sum-) "a436b8d370a26d189e735c968518dc40")
(setf (get glider_msg::cobamsg :datatype-) "glider_msg/cobamsg")
(setf (get glider_msg::cobamsg :definition-)
      "int32 a
int32 b
float32 c
string kata

")



(provide :glider_msg/cobamsg "a436b8d370a26d189e735c968518dc40")


